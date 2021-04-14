package people;
public class BeijingPeople extends ChinaPeople {
    @Override
    public void averageHeight(){
        height = 172.5;
        System.out.println("345678:"+ height + "87654");
    }
    
    @Override
    public void averageWeight(){
        weight = 70;
        System.out.println("123456:" + weight + "123456");
    }
    
    public void beijingOpera() {
        System.out.println("123456");
    }
}
