interface User {
    username: string;
    password: string;
    confirmPasword?: string;
}

let user: User;

user = { username:'carlos', password:'1234' };

interface controlPlane {
    accelerate(speed: number): number;
    stop(): void;
}

let car:controlPlane = {
    accelerate: function (speed: number) {
        return speed+1;
    },
    stop: function( ) {
        console.log('Se ha detenido');
    }
};

console.log( car.accelerate(1) );
car.stop()