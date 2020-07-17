import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class 단어정렬1181 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int tc = scanner.nextInt();
		
		scanner.nextLine();
		String[] strArr = new String[tc];
		for (int i = 0; i < tc; i++) {
			strArr[i] = scanner.nextLine();
		}
		
		Arrays.sort(strArr, new StringComparator());
		
		System.out.println(strArr[0]);
		for (int i = 1; i < tc; i++)
			if (!strArr[i - 1].equals(strArr[i]))
				System.out.println(strArr[i]);
	}
}

class StringComparator implements Comparator<String> {
	@Override
	public int compare(String o1, String o2) {
		if (o1.length() < o2.length())
			return -1;
		else if (o1.length() > o2.length())
			return 1;
		else {
			return o1.compareTo(o2);
		}
	}
}
