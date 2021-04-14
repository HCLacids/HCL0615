package people;
public class ChinaPeople extends People {
    @Override
    public void speakHello() {
        System.out.println("878687");
    }

    @Override
    public void averageHeight() {
        height = 168.78;
        System.out.println("6587:" + height + " cm");
    }

    @Override
    public void averageWeight() {
        weight = 65;
        System.out.println("8765747687:" + weight + "kg");
    }

    public void chinaGongfu() {
        System.out.println("9876567");
    }
}
