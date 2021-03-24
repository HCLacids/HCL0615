public class exp3 {
    public static void main(String[] args){
        Vehicle car1 = new Vehicle(0,0);
        car1.setPower(128);
        Vehicle car2 = new Vehicle(76,0);
        Vehicle car3 = new Vehicle(85,40.5);
        System.out.println("car1�Ĺ����ǣ�" + car1.getPower());
        System.out.println("car2�Ĺ����ǣ�" + car2.getPower());
        System.out.println("car3�Ĺ����ǣ�" + car3.getPower());
        car1.speedUp(80);
        car2.speedUp(100);
        car3.speedUp(30);
        System.out.println("car1Ŀǰ���ٶȣ�" + car1.getSpeed());
        System.out.println("car2Ŀǰ���ٶȣ�" + car2.getSpeed());
        System.out.println("car3Ŀǰ���ٶȣ�" + car3.getSpeed());
        car1.speedDown(10);
        car2.speedDown(20);
        car3.speedDown(30);
        System.out.println("car1Ŀǰ���ٶȣ�" + car1.getSpeed());
        System.out.println("car2Ŀǰ���ٶȣ�" + car2.getSpeed());
        System.out.println("car3Ŀǰ���ٶȣ�" + car3.getSpeed());

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