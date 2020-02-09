var user;
user = { username: 'carlos', password: '1234' };
var car = {
    accelerate: function (speed) {
        return speed + 1;
    }
};
console.log(car.accelerate(1));
car.stop();
