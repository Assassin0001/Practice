import { Component,ViewChild,AfterViewInit } from '@angular/core';
import { PostComponent } from './post/post.component';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements AfterViewInit {

  message: string ='Message from Typescript Command File';
  imgUrl: string ='https://th.bing.com/th/id/R.35b7cf10203ae316c59e65b9f0c6d60d?rik=PEZxCxVcGh5lEw&riu=http%3a%2f%2fs1.picswalls.com%2fwallpapers%2f2017%2f12%2f11%2fnature-desktop-background_123026895_313.jpg&ehk=rvr98svQL12hNeYouWPK7AvyXVnHaRJWDvovllsJxRs%3d&risl=1&pid=ImgRaw&r=0';
  title = 'AngIntro';
  parentMessage: string = 'Message Changed';
  bool: boolean = false;

  @ViewChild(PostComponent) childComp;

  constructor(){
    console.log(this.childComp);
  }

  buttonClick(){
    console.log('ButtonClick Event Worked');
  }

  //Listen to received message via Output
  receiveMessage($event){
    console.log($event);
  }
  ngAfterViewInit(){
    console.log(this.childComp);
    this.message = this.childComp.childMessage;
}
}
