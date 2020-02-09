class Car {
    engineName: string;
    gears: number;
    private speed: number;

    constructor(speed: number) {
        this.speed = speed || 0;
    }

    accelerate(): void {
        this.speed++;
    }

    getSpeed(): void {
        console.log(this.speed);
    }
}

let car = new Car(5);

car.accelerate();
car.getSpeed();