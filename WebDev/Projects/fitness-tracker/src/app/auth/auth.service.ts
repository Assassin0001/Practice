import { Injectable } from '@angular/core';
import { Router } from '@angular/router';
import { AuthData } from './auth-data.model';
import { Subject } from 'rxjs';
import {
  getAuth,
  createUserWithEmailAndPassword,
  signInWithEmailAndPassword,
  signOut,
  User,
  onAuthStateChanged,
} from 'firebase/auth';
import { TrainingService } from '../training/training.service';
import { UIService } from '../shared/ui.service';

@Injectable()
export class AuthService {
  private isAuthenticated = false;
  private user: User | null = null;
  //Observable
  authChange = new Subject<boolean>();

  constructor(
    private router: Router,
    private trainingService: TrainingService,
    private uiService: UIService
  ) {
    // Call the auth listener when the service is created
    this.initAuthListener();
  }

  initAuthListener() {
    const auth = getAuth();

    // Use onAuthStateChanged to listen for authentication state changes
    onAuthStateChanged(auth, (user) => {
      if (user) {
        // User is authenticated
        this.isAuthenticated = true;
        this.authChange.next(true);
        this.router.navigate(['/training']);
      } else {
        // User is not authenticated
        this.trainingService.cancelSubscriptions();
        this.authChange.next(false);
        this.router.navigate(['/login']);
        this.isAuthenticated = false;
      }
    });
  }

  registerUser(authData: AuthData) {
    this.uiService.lodaingStateChanged.next(true);
    const auth = getAuth();

    createUserWithEmailAndPassword(auth, authData.email, authData.password)
      .then((res) => {
        this.uiService.lodaingStateChanged.next(false);
        console.log(res);
      })
      .catch((error) => {
        this.uiService.lodaingStateChanged.next(false);
        this.uiService.showSnackBar(error.message, null, 3000);
      });
  }

  login(authData: AuthData) {
    this.uiService.lodaingStateChanged.next(true);
    const auth = getAuth();

    signInWithEmailAndPassword(auth, authData.email, authData.password)
      .then((result) => {
        this.uiService.lodaingStateChanged.next(false);
        console.log(result);
      })
      .catch((error) => {
        this.uiService.lodaingStateChanged.next(false);
        this.uiService.showSnackBar(error.message, null, 3000);
      });
  }

  logout() {
    const auth = getAuth();
    signOut(auth)
      .then()
      .catch((error) => {
        console.error('Logout Failed', error);
      });
  }

  isAuth() {
    return this.isAuthenticated;
  }
}
