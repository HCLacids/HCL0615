public class BeijingPeople extends ChinaPeople {
    @Override
    public void averageHeight(){
        height = 172.5;
        System.out.println("�����˵�ƽ�����:"+ height + "����");
    }
    
    @Override
    public void averageWeight(){
        weight = 70;
        System.out.println("�����˵�ƽ������:" + weight + "����");
    }
    
    public void beijingOpera() {
        System.out.println("���������¡�����������");
    }
}
