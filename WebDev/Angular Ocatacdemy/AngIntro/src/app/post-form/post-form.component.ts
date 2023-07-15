import { Component } from '@angular/core';

@Component({
  selector: 'app-post-form',
  templateUrl: './post-form.component.html',
  styleUrls: ['./post-form.component.css']
})
export class PostFormComponent {
  Username: string;
  UserEmail: string;
  Address: string;

  userArray: Array<any> = [];
  onClick(){
    this.userArray.push({
      "name": this.Username, "email": this.UserEmail, "address": this.Address
    });

    console.log(this.userArray);
  }

  onDelete(index){
    this.userArray.splice(index, 1);
  }
}
