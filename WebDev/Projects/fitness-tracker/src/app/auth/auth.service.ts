import { Injectable } from '@angular/core';
import { Router } from '@angular/router';
import { User } from './user.model';
import { AuthData } from './auth-data.model';
import { Subject } from 'rxjs';
import {
  getAuth,
  createUserWithEmailAndPassword,
} from 'firebase/auth';

@Injectable()
export class AuthService {
  //user can be either User Object or Null
  private user: User | null = null;
  //Observable
  authChange = new Subject<boolean>();

  constructor(private router: Router) {}

  registerUser(authData: AuthData) {
    const auth = getAuth();

    if (!authData.password || authData.password.trim() === '') {
      console.error('Password is missing or empty');
      return;
    }

    createUserWithEmailAndPassword(auth, authData.email, authData.password)
      .then((userCredential) => {
        this.user = {
          email: userCredential.user.email!,
          userId: userCredential.user.uid,
        };
        this.authSuccessfully();
      })
      .catch((error) => console.error('Registration failed:', error));
  }

  login(authData: AuthData) {
    this.user = {
      email: authData.email,
      userId: Math.round(Math.random() * 10000).toString(),
    };
    this.authSuccessfully();
  }

  logout() {
    this.user = null;
    //Mark as falseF
    this.authChange.next(false);
  }

  // New Object using Object-Spread operator {...}
  getUser() {
    return { ...this.user };
  }

  isAuth() {
    return this.user != null;
  }

  private authSuccessfully() {
    //Mark as true and navigate
    this.authChange.next(true);
    this.router.navigate(['/training']);
  }
}
