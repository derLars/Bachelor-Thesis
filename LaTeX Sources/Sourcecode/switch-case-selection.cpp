...
Shape* neededObj;
switch(externalSignal) {
    case 0:
        neededObj = new Triangle();
        break;
    case 1:
        neededObj = new Rectangle();
        break;
    case 2:
        neededObj = new Circle();
        break;
}
...
