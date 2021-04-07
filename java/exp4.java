public class exp4 {
    public static void main(String args[]) {
        ChinaPeople chinaPeople = new ChinaPeople();
        AmericanPeople americanPeople = new AmericanPeople();
        BeijingPeople beijingPeople = new BeijingPeople();
        chinaPeople.speakHello();
        americanPeople.speakHello();
        beijingPeople.speakHello();
        chinaPeople.averageHeight();
        americanPeople.averageHeight();
        beijingPeople.averageHeight();
        chinaPeople.averageWeight();
        americanPeople.averageWeight();
        beijingPeople.averageWeight();
        chinaPeople.chinaGongfu();
        americanPeople.americanBoxing();
        beijingPeople.beijingOpera();
        beijingPeople.chinaGongfu();
    }
}
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

public class ChinaPeople extends People {
    @Override
    public void speakHello() {
        System.out.println("您好");
    }

    @Override
    public void averageHeight() {
        height = 168.78;
        System.out.println("中国人的平均身高:" + height + " 厘米");
    }

    @Override
    public void averageWeight() {
        weight = 65;
        System.out.println("中国人的平均体重:" + weight + "公斤");
    }

    public void chinaGongfu() {
        System.out.println("坐如钟,站如松,睡如弓");
    }
}

public class BeijingPeople extends ChinaPeople {
    @Override
    public void averageHeight() {
        height = 172.5;
        System.out.println("北京人的平均身高:" + height + "厘米");
    }

    @Override
    public void averageWeight() {
        weight = 70;
        System.out.println("北京人的平均体重:" + weight + "公斤");
    }

    public void beijingOpera() {
        System.out.println("花脸、青衣、花旦和老生");
    }
}

public class AmericanPeople extends People {
    @Override
    public void speakHello() {
        System.out.println("How do you do");
    }

    @Override
    public void averageHeight() {
        height = 176;
        System.out.println("American's average height:" + height + "cm");
    }

    @Override
    public void averageWeight() {
        weight = 75;
        System.out.println("American's average weight:" + weight + " kg");
    }

    public void americanBoxing() {
        System.out.println("直拳、钩拳、组合拳");
    }
}

