import { Component, EventEmitter, OnDestroy, OnInit, Output } from '@angular/core';
import { AuthService } from 'src/app/auth/auth.service';
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css'],
})
export class HeaderComponent implements OnInit, OnDestroy {
  @Output() sidenavToggle = new EventEmitter<void>();
  isAuth: boolean = false;
  authSubscription!: Subscription;

  constructor(private authService: AuthService) {}

  onToggle() {
    this.sidenavToggle.emit();
  }

  ngOnInit() {
    this.authSubscription = this.authService.authChange.subscribe((authStatus) => {
      this.isAuth = authStatus;
    });
  }

  onLogout(){
    this.authService.logout();
  }

  ngOnDestroy() {
      this.authSubscription.unsubscribe();
  }

}
