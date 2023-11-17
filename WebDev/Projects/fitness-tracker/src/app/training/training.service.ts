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
import { Subject } from 'rxjs';
import { Injectable } from '@angular/core';

@Injectable()
export class TrainingService {
  exerciseChanged = new Subject<Exercise>();
  exercisesChanged = new Subject<Exercise[]>();
  finishedExercisesChanged = new Subject<Exercise[]>();
  private availableExercises: Exercise[] = [];
  private runningExercise: Exercise;

  db: Firestore;

  constructor() {
    const app = initializeApp(environment.firebaseConfig);
    this.db = getFirestore(app);
  }

  fetchvailableExercises() {
    const exercisesCollection = collection(this.db, 'availableExercises');

    getDocs(exercisesCollection).then((querySnapshot) => {
      const exercises = querySnapshot.docs.map((doc) => {
        const data = doc.data();
        return {
          id: doc.id,
          name: data['name'],
          duration: data['duration'],
          calories: data['calories'],
        };
      });

      this.availableExercises = exercises;
      this.exercisesChanged.next([...this.availableExercises]);
    });
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

    // Read About Below Functions
    getDocs(finishedExercisesCollection).then((querySnapshot) => {
      const exercises = querySnapshot.docs.map((doc) => doc.data() as Exercise);
      this.finishedExercisesChanged.next(exercises);
    });
  }

  private addDataToDatabase(exercise: Exercise){
    const finishedExercisesCollection = collection(this.db, 'finishedExercises');
    addDoc(finishedExercisesCollection, exercise);
  }
}
