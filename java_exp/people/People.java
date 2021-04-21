package people;
public class People {
    protected double weight;
    protected double height;

    public void speakHello() {
        System.out.println("yayayaya");
    }

    public void averageHeight() {
        height = 173;
        System.out.println("average height:" + height);
    }

    public void averageWeight() {
        weight = 70;
        System.out.println("average weight:" + weight);
    }
}
