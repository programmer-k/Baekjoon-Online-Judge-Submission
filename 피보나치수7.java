import java.math.BigInteger;
import java.util.Scanner;

// �ð� �ʰ�

public class �Ǻ���ġ��7 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		long num = scanner.nextLong();
		
		BigInteger f1 = new BigInteger("0"), f2 = new BigInteger("1"), f3 = null;
		
		scanner.close();
		
		// ���� ����
		if (num == 0 || num == 1) {
			System.out.println(num);
			return;
		}
		
		// ���
		for (long i = 1; i < num; i++) {
			f3 = f1.add(f2);
			f1 = f2;
			f2 = f3;
		}
		
		// ���
		System.out.println(f3.remainder(new BigInteger("1000000007")));
	}

}
