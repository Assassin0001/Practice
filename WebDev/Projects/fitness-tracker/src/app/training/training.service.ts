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
import { Subject, Subscription, from, map } from 'rxjs';
import { Injectable } from '@angular/core';
import { UIService } from '../shared/ui.service';
import * as UI from '../shared/ui.actions';
import * as fromRoot from '../app.reducer';
import { Store } from '@ngrx/store';

@Injectable()
export class TrainingService {
  exerciseChanged = new Subject<Exercise>();
  exercisesChanged = new Subject<Exercise[]>();
  finishedExercisesChanged = new Subject<Exercise[]>();
  private availableExercises: Exercise[] = [];
  private runningExercise: Exercise;
  private fbSubs: Subscription[] = [];

  db: Firestore;
  constructor(private uiService: UIService, private store: Store<fromRoot.State>) {
    const app = initializeApp(environment.firebaseConfig);
    this.db = getFirestore(app);
  }

  fetchAvailableExercises() {
    this.store.dispatch(new UI.StartLoading());
    const exercisesCollection = collection(this.db, 'availableExercises');

    this.fbSubs.push(
      from(getDocs(exercisesCollection)).pipe(
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
      ).subscribe((exercises) => {
        this.store.dispatch(new UI.StopLoading());
        this.availableExercises = exercises;
        this.exercisesChanged.next([...this.availableExercises]);
      }, error =>{
        this.store.dispatch(new UI.StopLoading());
        this.uiService.showSnackBar(('Fetching Exercises Failed, Try again later'), null, 3000);
        this.exercisesChanged.next([null]);
      })
    );
  }

  cancelSubscriptions(){
    this.fbSubs.forEach(sub => sub.unsubscribe());
  }

  getRunningExercise() {
    return { ...this.runningExercise };
  }

  startExercise(selectedId: string) {
    this.runningExercise = this.availableExercises.find(
      (ex) => ex.id === selectedId
    )!;
    this.exerciseChanged.next({ ...this.runningExercise });
  }

  completeExercise() {
    this.addDataToDatabase({
      ...this.runningExercise,
      date: new Date(),
      state: 'completed',
    });
    this.runningExercise = null;
    this.exerciseChanged.next(null);
  }

  cancelExercise(progress: number) {
    this.addDataToDatabase({
      ...this.runningExercise,
      duration: this.runningExercise.duration * (progress / 100),
      calories: this.runningExercise.calories * (progress / 100),
      date: new Date(),
      state: 'cancelled',
    });
    this.runningExercise = null;
    this.exerciseChanged.next(null);
  }

  fetchCompletedorCancelledExercises() {
    const finishedExercisesCollection = collection(this.db, 'finishedExercises');

    this.fbSubs.push(
      from(getDocs(finishedExercisesCollection)).pipe(
        map((querySnapshot) => querySnapshot.docs.map((doc) => doc.data() as Exercise))
      ).subscribe(
        (exercises) => {
          this.finishedExercisesChanged.next(exercises);
        },
        (error) => {
          this.store.dispatch(new UI.StopLoading());
          this.uiService.showSnackBar('Fetching Completed or Cancelled Exercises Failed, Try again later', null, 3000);
        }
      )
    );
  }

  private addDataToDatabase(exercise: Exercise){
    const finishedExercisesCollection = collection(this.db, 'finishedExercises');
    addDoc(finishedExercisesCollection, exercise);
  }
}
