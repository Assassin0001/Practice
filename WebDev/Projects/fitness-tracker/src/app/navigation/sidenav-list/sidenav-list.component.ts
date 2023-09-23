import { Subscription } from 'rxjs';
import { Component, EventEmitter, OnInit, Output, OnDestroy } from '@angular/core';
import { AuthService } from 'src/app/auth/auth.service';

@Component({
  selector: 'app-sidenav-list',
  templateUrl: './sidenav-list.component.html',
  styleUrls: ['./sidenav-list.component.css']
})
export class SidenavListComponent implements OnInit, OnDestroy{
  @Output() closeSidenav = new EventEmitter <void>();
  isAuth: boolean = false;
  authSubscription!: Subscription;

  constructor(private authService: AuthService){}

  ngOnInit(){
    this.authSubscription = this.authService.authChange.subscribe(authStatus =>{
      this.isAuth = authStatus;
    })
  }

  onClose(){
    this.closeSidenav.emit();
  }

  onLogout(){
    this.authService.logout();
    this.onClose();
  }

  ngOnDestroy(){
    this.authSubscription.unsubscribe();
  }
}