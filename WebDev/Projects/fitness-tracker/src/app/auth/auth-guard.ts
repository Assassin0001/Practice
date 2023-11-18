import { AuthService } from 'src/app/auth/auth.service';
import { Injectable } from '@angular/core';
import {
  CanLoad,
  CanActivate,
  Router,
  ActivatedRouteSnapshot,
  RouterStateSnapshot,
  Route,
} from '@angular/router';

@Injectable()
export class AuthGuard implements CanActivate {
  constructor(private authService: AuthService, private router: Router) {}

  canActivate(route: ActivatedRouteSnapshot, state: RouterStateSnapshot) {
    if (this.authService.isAuth()) {
      return true;
    } else {
      this.router.navigate(['/login']);
      return false;
    }
  }

  canLoad(route: Route) {
    if (this.authService.isAuth()) {
      return true;
    } else {
      this.router.navigate(['/login']);
      return false;
    }
  }
}
