public class exp3 {
    public static void main(String[] args){
        Vehicle car1 = new Vehicle(0,0);
        car1.setPower(128);
        Vehicle car2 = new Vehicle(76,0);
        Vehicle car3 = new Vehicle(85,40.5);
        System.out.println("car1的功率是：" + car1.getPower());
        System.out.println("car2的功率是：" + car2.getPower());
        System.out.println("car3的功率是：" + car3.getPower());
        car1.speedUp(80);
        car2.speedUp(100);
        car3.speedUp(30);
        System.out.println("car1目前的速度：" + car1.getSpeed());
        System.out.println("car2目前的速度：" + car2.getSpeed());
        System.out.println("car3目前的速度：" + car3.getSpeed());
        car1.speedDown(10);
        car2.speedDown(20);
        car3.speedDown(30);
        System.out.println("car1目前的速度：" + car1.getSpeed());
        System.out.println("car2目前的速度：" + car2.getSpeed());
        System.out.println("car3目前的速度：" + car3.getSpeed());

    }
}

class Vehicle {
    // instance fields
    private double speed;
    private int power;

    // cosntructor
    public Vehicle(int p, double s) {
        power = p;
        speed = s;
    }

    // methods
    public void speedUp(int s) {
        speed += s;
    }

    public void speedDown(int d) {
        speed -= d;
    }

    public void setPower(int p) {
        power = p;
    }

    public double getSpeed() {
        return speed;
    }

    public int getPower() {
        return power;
    }
}