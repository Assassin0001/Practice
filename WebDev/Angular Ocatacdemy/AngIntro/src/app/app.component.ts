import { Component,ViewChild,AfterViewInit } from '@angular/core';
import { PostComponent } from './post/post.component';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements AfterViewInit {
  title = 'AngIntro';
  parentMessage: string = 'Message Changed';
  message: string;

  @ViewChild(PostComponent) childComp;

  constructor(){
    console.log(this.childComp);
  }

  ngAfterViewInit(){
      console.log(this.childComp);
      this.message = this.childComp.childMessage;
  }
}
