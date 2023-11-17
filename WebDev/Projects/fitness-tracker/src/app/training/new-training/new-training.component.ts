import { Exercise } from './../exercise.model';
import { TrainingService } from './../training.service';
import { Component, EventEmitter, Injectable, OnDestroy, OnInit, Output } from '@angular/core';
import { NgForm } from '@angular/forms';
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-new-training',
  templateUrl: './new-training.component.html',
  styleUrls: ['./new-training.component.css'],
})
@Injectable()
export class NewTrainingComponent implements OnInit, OnDestroy {
  @Output() trainingStart = new EventEmitter<void>();
  exercises: Exercise[];
  exerciseSubscription: Subscription;

  constructor(private trainingService: TrainingService) {}

  ngOnInit() {
    this.exerciseSubscription = this.trainingService.exercisesChanged.subscribe(
      (exercises) => {
        this.exercises = exercises;
      }
    );
    this.trainingService.fetchvailableExercises();
  }

  onstartTraining(form: NgForm) {
    this.trainingService.startExercise(form.value.exercise);
  }

  ngOnDestroy() {
    this.exerciseSubscription.unsubscribe();
  }
}
