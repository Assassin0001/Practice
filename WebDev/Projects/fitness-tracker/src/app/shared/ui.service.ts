import { Subject } from "rxjs";

export class UIService{
  lodaingStateChanged = new Subject<boolean>();
}
