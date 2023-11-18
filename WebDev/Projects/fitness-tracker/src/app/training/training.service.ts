import { Exercise } from './exercise.model';
import {
  Firestore,
  addDoc,
  collection,
  getDocs,
  getFirestore,
} from 'firebase/firestore';
import { initializeApp } from 'firebase/app';
import { environment } from 'src/environments/environment';
import { Subject, Subscription, from, map, take } from 'rxjs';
import { Injectable } from '@angular/core';
import { UIService } from '../shared/ui.service';
import * as UI from '../shared/ui.actions';
import * as Training from './training.actions';
import * as fromTraining from './training.reducer';
import { Store } from '@ngrx/store';

@Injectable()
export class TrainingService {
  exerciseChanged = new Subject<Exercise>();
  exercisesChanged = new Subject<Exercise[]>();
  finishedExercisesChanged = new Subject<Exercise[]>();
  private fbSubs: Subscription[] = [];

  db: Firestore;
  constructor(
    private uiService: UIService,
    private store: Store<fromTraining.State>
  ) {
    const app = initializeApp(environment.firebaseConfig);
    this.db = getFirestore(app);
  }

  fetchAvailableExercises() {
    this.store.dispatch(new UI.StartLoading());
    const exercisesCollection = collection(this.db, 'availableExercises');

    this.fbSubs.push(
      from(getDocs(exercisesCollection))
        .pipe(
          map((querySnapshot) =>
            querySnapshot.docs.map((doc) => {
              const data = doc.data();
              return {
                id: doc.id,
                name: data['name'],
                duration: data['duration'],
                calories: data['calories'],
              };
            })
          )
        )
        .subscribe(
          (exercises) => {
            this.store.dispatch(new UI.StopLoading());
            this.store.dispatch(new Training.SetAvailableTrainings(exercises));
          },
          (error) => {
            this.store.dispatch(new UI.StopLoading());
            this.uiService.showSnackBar(
              'Fetching Exercises Failed, Try again later',
              null,
              3000
            );
            this.exercisesChanged.next([null]);
          }
        )
    );
  }

  cancelSubscriptions() {
    this.fbSubs.forEach((sub) => sub.unsubscribe());
  }

  startExercise(selectedId: string) {
    this.store.dispatch(new Training.StartTraining(selectedId));
  }

  completeExercise() {
    this.store.select(fromTraining.getActiveTraining).pipe(take(1)).subscribe((ex) => {
      this.addDataToDatabase({
        ...ex,
        date: new Date(),
        state: 'completed',
      });
      this.store.dispatch(new Training.StopTraining());
    });
  }

  cancelExercise(progress: number) {
    this.store.select(fromTraining.getActiveTraining).pipe(take(1)).subscribe((ex) => {
      this.addDataToDatabase({
        ...ex,
        duration: ex.duration * (progress / 100),
        calories: ex.calories * (progress / 100),
        date: new Date(),
        state: 'cancelled',
      });
      this.store.dispatch(new Training.StopTraining());
    });
  }

  fetchCompletedorCancelledExercises() {
    const finishedExercisesCollection = collection(
      this.db,
      'finishedExercises'
    );

    this.fbSubs.push(
      from(getDocs(finishedExercisesCollection))
        .pipe(
          map((querySnapshot) =>
            querySnapshot.docs.map((doc) => doc.data() as Exercise)
          )
        )
        .subscribe(
          (exercises) => {
            this.store.dispatch(new Training.SetAvailableTrainings(exercises));
          },
          (error) => {
            this.store.dispatch(new UI.StopLoading());
            this.uiService.showSnackBar(
              'Fetching Completed or Cancelled Exercises Failed, Try again later',
              null,
              3000
            );
          }
        )
    );
  }

  private addDataToDatabase(exercise: Exercise) {
    const finishedExercisesCollection = collection(
      this.db,
      'finishedExercises'
    );
    addDoc(finishedExercisesCollection, exercise);
  }
}
