import { Component,ViewChild,AfterViewInit } from '@angular/core';
import { PostComponent } from './post/post.component';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})

export class AppComponent implements AfterViewInit {

  /*title = 'AngIntro';
  message: string ='Message from Typescript Command File';
  parentMessage: string = 'Message Changed';
  bool: boolean = false;
  userName: string;
  textValue: string = "Value is coming from component";*/

  //Two Way Data Binding Exercise
  imgUrl: string;
  postTitle: string;
  postDetails: string;
  postUrl: string;
  addBackground: boolean;


  @ViewChild(PostComponent) childComp;

  constructor(){
    console.log(this.childComp);
  }

  /*buttonClick(){
    console.log('ButtonClick Event Worked');
  }

  //Event Filtering and Two Way Data Binding
  onKeyup(){
    console.log(this.textValue);
  }

  //Listen to received message via Output
  receiveMessage($event){
    console.log($event);
  }
  */
  ngAfterViewInit(){
  //  console.log(this.childComp);
  //  this.message = this.childComp.childMessage;

}

}
