import { UIService } from './../../shared/ui.service';
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
  isLoading = true;
  private loadingSubscription: Subscription;

  constructor(private trainingService: TrainingService, private uiService: UIService) {}

  ngOnInit() {
    this.loadingSubscription = this.uiService.lodaingStateChanged.subscribe(isLoading =>{
      this.isLoading = isLoading;
    });
    this.exerciseSubscription = this.trainingService.exercisesChanged.subscribe(
      (exercises) => {
        this.exercises = exercises;
      }
    );
    this.fetchExercises();
  }

  fetchExercises(){
    this.trainingService.fetchAvailableExercises();
  }

  onstartTraining(form: NgForm) {
    this.trainingService.startExercise(form.value.exercise);
  }

  ngOnDestroy() {
    if(this.exerciseSubscription){
      this.exerciseSubscription.unsubscribe();
    }
    if(this.loadingSubscription){
      this.loadingSubscription.unsubscribe();
    }
  }
}
