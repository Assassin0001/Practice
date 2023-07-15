import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { NavbarComponent } from './navbar/navbar.component';
import { PostComponent } from './post/post.component';
import { PostListComponent } from './post-list/post-list.component';
import { PostFormComponent } from './post-form/post-form.component';

@NgModule({
  declarations: [AppComponent, NavbarComponent, PostComponent, PostListComponent, PostFormComponent],
  imports: [BrowserModule, AppRoutingModule,FormsModule],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule { }
