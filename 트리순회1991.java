import java.util.Scanner;

public class 트리순회1991 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		char data = 'A';
		Node[] arr = new Node[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Node(data);
			data += 1;
		}
		
		// \n 버리기
		scanner.nextLine();
		for (int i = 0; i < n; i++) {
			char root, left, right;
			String temp = scanner.nextLine();
			root = temp.charAt(0);
			left = temp.charAt(2);
			right = temp.charAt(4);
			
			if (left == '.')
				arr[root - 'A'].left = null;
			else
				arr[root - 'A'].left = arr[left - 'A'];
			
			if (right == '.')
				arr[root - 'A'].right = null;
			else
				arr[root - 'A'].right = arr[right - 'A'];
		}
		
		Tree tree = new Tree(arr[0]);
		
		tree.doPreorderTraversal(arr[0]);
		System.out.println();
		tree.doInorderTraversal(arr[0]);
		System.out.println();
		tree.doPostorderTraversal(arr[0]);
		
		scanner.close();
	}
}

class Node {
	public char data;
	public Node left;
	public Node right;
	
	public Node(char data) {
		this.data = data;
	}
}

class Tree {
	private Node root;
	
	public Tree(Node root) {
		this.root = root;
	}
	
	public void doInorderTraversal(Node node) {
		if (node == null)
			return;
		
		doInorderTraversal(node.left);
		System.out.print(node.data);
		doInorderTraversal(node.right);
	}
	
	public void doPreorderTraversal(Node node) {
		if (node == null)
			return;
		
		System.out.print(node.data);
		doPreorderTraversal(node.left);
		doPreorderTraversal(node.right);
	}
	
	public void doPostorderTraversal(Node node) {
		if (node == null)
			return;
		
		doPostorderTraversal(node.left);
		doPostorderTraversal(node.right);
		System.out.print(node.data);
	}
}