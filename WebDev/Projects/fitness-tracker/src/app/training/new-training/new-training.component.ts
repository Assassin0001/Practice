import { TrainingService } from './../training.service';
import {
  Component,
  EventEmitter,
  Injectable,
  OnInit,
  Output,
} from '@angular/core';
import { Exercise } from '../exercise.model';
import { NgForm } from '@angular/forms';

@Component({
  selector: 'app-new-training',
  templateUrl: './new-training.component.html',
  styleUrls: ['./new-training.component.css'],
})
@Injectable()
export class NewTrainingComponent implements OnInit {
  @Output() trainingStart = new EventEmitter<void>();
  constructor(private trainingService: TrainingService) {}
  exercises: Exercise[] = [];

  ngOnInit() {
    this.exercises = this.trainingService.getAvailableExercises();
  }

  onstartTraining(form: NgForm) {
    this.trainingService.startExercise(form.value.exercise);
  }
}
