public class ChinaPeople extends People {
    @Override
    public void speakHello() {
        System.out.println("����");
    }

    @Override
    public void averageHeight() {
        height = 168.78;
        System.out.println("�й��˵�ƽ�����:" + height + " ����");
    }

    @Override
    public void averageWeight() {
        weight = 65;
        System.out.println("�й��˵�ƽ������:" + weight + "����");
    }

    public void chinaGongfu() {
        System.out.println("������,վ����,˯�繭");
    }
}
