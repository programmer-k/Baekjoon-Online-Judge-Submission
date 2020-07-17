

//import java.io.BufferedReader;
//import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
// import java.util.Scanner;

public class �������ϱ�411931 {

	public static void main(String[] args) throws Exception {
		// ���� ���� 2750�� - �����ϴ� ������ ����� ������ Ȯ���غ���
		// �ð��ʰ���. - ������� �ٲ�µ��� �׷��� �� ���� �Ƹ� O(log n)������ ��ȸ�ϴµ� �ð��� �����ɸ� �� ����.
		// �̻��ϰ� �� �����ϱ� 3�� �´µ�, �� �����ϱ� 2�� Ʋ����.. -> �¾��� ������ �̰� case1, 3���� �ణ�� ������ ���ܼ� ����� ���ư��� �ϴµ�, Ʈ���� ���̰� �� Ŀ�� �ɸ� �� ����.
		// �� �����ϱ� 1, 2, 3 �� �ڵ�� �� �����.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		RedBlackTree tree = new RedBlackTree();
		// Scanner scanner = new Scanner(System.in);
		
		int tc = Integer.parseInt(br.readLine());
		for (int i = 0; i < tc; i++) {
			int num = Integer.parseInt(br.readLine());
			tree.insert(num, Integer.toString(num));
			//System.out.println("Hello:" + tree.root.key + tree.root.parent);
		}
		
		tree.inorderTraversal(bw);
		// scanner.close();
		br.close();
		bw.close();
	}
}

// ��Ŭ�������� ������ ���� ��� �Ʒ��� Ŭ���� 2���� �ּ� ó�� �س�����.

/*class RedBlackNode {
	public boolean red;
	public int key;
	public String payload;
	public RedBlackNode parent;
	public RedBlackNode left, right;
	
	// �׽�Ʈ�� ���� �ڵ�
	public int count = 1;
}*/





/*class RedBlackTree {
	public RedBlackNode root;
	
	public RedBlackTree() {
		// ��Ʈ�� ���� ���� null ������ ǥ��
		root = null;
	}
	
	public boolean isEmpty() {
		if (root == null)
			return true;
		else
			return false;
	}
	
	public boolean hasLeftChild(RedBlackNode node) {
		if (node.left == null)
			return false;
		else
			return true;
	}
	
	public boolean hasRightChild(RedBlackNode node) {
		if (node.right == null)
			return false;
		else
			return true;
	}
	
	public boolean insert(int k, String p) {
		// ���� ������ case - RedBlackTree�� ����� ��,
		if (root == null) {
			root = new RedBlackNode();
			root.key = k;
			root.payload = p;
			root.left = null;	// RedBlackTree���� insertion�� �� ��, ���� ���� �ϴ� ���� ������ BinarySearchTree���� �ϴ� ��ó�� root�κ��� �������� ���ε�, �׷��ٸ� node�� left, right child�� null�� ���ۿ� ����.
			root.right = null;
			root.parent = null;
			root.red = false;
			return true;
		}
		
		// ������ ��ġ ã��
		RedBlackNode prev = null;
		RedBlackNode cur = root;
		boolean left = false;
		while (cur != null) {
			if (cur.key < k) {
				prev = cur;
				cur = cur.left;
				left = true;
			} else if (cur.key > k) {
				prev = cur;
				cur = cur.right;
				left = false;
			} else {
				// k�� �̹� �����ϸ�, �ƹ��͵� ���� �ʰ� ��ȯ�Ѵ�.
				// return false;
				

				// �׽�Ʈ�� ���� �ڵ�
				cur.count++;
				return true;
			}
		}
		
		RedBlackNode x;
		
		// �����ϱ�
		if (left) {
			prev.left = new RedBlackNode();
			prev.left.key = k;
			prev.left.parent = prev;
			prev.left.payload = p;
			prev.left.red = true;
			prev.left.left = null;
			prev.left.right = null;
			x = prev.left;
		} else {
			prev.right = new RedBlackNode();
			prev.right.key = k;
			prev.right.parent = prev;
			prev.right.payload = p;
			prev.right.red = true;
			prev.right.left = null;
			prev.right.right = null;
			x = prev.right;
		}
		
		// System.out.println();
		//System.out.println("�Է��� " + k);
		//System.out.println();
		
		while (x != root && x.parent.red) {
			if (x.parent == x.parent.parent.left) {
				// uncle�� null�ϼ��� ���� -> NullPointerException�� �����ϱ� ���� �ڵ� �߰�
				if (x.parent.parent.right != null && x.parent.parent.right.red) {
					x.parent.red = false;
					x.parent.parent.right.red = false;
					x.parent.parent.red = true;
					x = x.parent.parent;
					// System.out.println("case1");
					
				} else {
					if (x == x.parent.right) {
						x.parent.parent.left = x;
						RedBlackNode tempA = x.parent;
						x.parent = x.parent.parent;
						tempA.parent = x;
						tempA.right = x.left;
						x.left = tempA;
						if (tempA.right != null)
							tempA.right.parent = tempA;
						x = tempA;
						// System.out.println("case2!!");
					}
					// System.out.println("case3");
					x.parent.red = false;
					x.parent.parent.red = true;
					if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.right)		// ���̰� �� �� �̺κ��� ����, ���̰� ª�� ��, root�� �ٲٴ� �� ����
						x.parent.parent.parent.right = x.parent;
					else if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.left)
						x.parent.parent.parent.left = x.parent;
					RedBlackNode temp = x.parent.parent.parent;
					x.parent.parent.parent = x.parent;
					x.parent.parent.left = x.parent.right;
					x.parent.right = x.parent.parent;
					
					if (x.parent.right.left != null)
						x.parent.right.left.parent = x.parent.right;
					
					x.parent.parent = temp;
					x = root;
					
					// 5, 3, 2�� ������, root�� 5�� ����Ű�� �ֱ� ������, 5�� ����� �Ǵ� ��Ȳ�� �߻���. �׷��Ƿ� root�� �ٲ������.
					// �� ��, �ٲ��� root�� parent���� null�� �ٽ� �����������.
					if (root.parent != null) {
						root = root.parent;
						root.parent = null;
					}
				}
			} else {
				// ���� �ڵ忡�� ������ ���� �Ȱ��� NullPointerException �߻��� �� ����. (uncle�� null�� ���)
				if (x.parent.parent.left != null && x.parent.parent.left.red) {
					x.parent.red = false;
					x.parent.parent.left.red = false;
					x.parent.parent.red = true;
					x = x.parent.parent;
					// System.out.println("case1");
					// inorderTraversal();
					// System.out.println(root.key);
					// System.out.println(root.parent);
				} else {
					if (x == x.parent.left) {
						x.parent.parent.right = x;
						RedBlackNode tempA = x.parent;
						x.parent = x.parent.parent;
						tempA.parent = x;
						tempA.left = x.right;
						x.right = tempA;
						if (tempA.left != null)
							tempA.left.parent = tempA;
						x = tempA;
						// System.out.println("case2!");
					}
					// System.out.println("case3 - !!");
					x.parent.red = false;
					x.parent.parent.red = true;
					// parent�� parent�� parent�� ������ ��ħ.
					if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.left)		// ���̰� �� �� �̺κ��� ����, ���̰� ª�� ��, root�� �ٲٴ� �� ����
						x.parent.parent.parent.left = x.parent;
					else if (x.parent.parent.parent != null && x.parent.parent == x.parent.parent.parent.right)
						x.parent.parent.parent.right = x.parent;
					RedBlackNode temp = x.parent.parent.parent;
					// System.out.println("temp:" + x.parent.parent.parent);
					x.parent.parent.parent = x.parent;
					x.parent.parent.right = x.parent.left;
					x.parent.left = x.parent.parent;
					
					if (x.parent.left.right != null)
						x.parent.left.right.parent = x.parent.left;
					
					x.parent.parent = temp;
					
					x = root;
					
					// ���� ���� ��Ȳ�� ����ؼ�
					if (root.parent != null) {
						root = root.parent;
						root.parent = null;
					}
				}
			}
			// System.out.println(x.key);
		}
		root.red = false;
		
		
		// inorderTraversal();
		return true;
	}
	
	public String query(int k) {
		// ���� ������ case - RedBlackTree�� ����� ��,
		if (root == null) {
			return null;
		}
		
		// ������ ��ġ ã��
		RedBlackNode prev = null;
		RedBlackNode cur = root;
		boolean left = false;
		while (cur != null) {
			if (cur.key > k) {
				prev = cur;
				cur = cur.left;
				left = true;
			} else if (cur.key < k) {
				prev = cur;
				cur = cur.right;
				left = false;
			} else {
				// k�� �̹� �����ϸ�, �ƹ��͵� ���� �ʰ� ��ȯ�Ѵ�.
				return null;
			}
		}
		
		if (left) {
			return prev.left.payload;
		} else {
			return prev.right.payload;
		}
	}
	
	// �׽�Ʈ�� ���� �Լ�
	public void doInorderTraversal(RedBlackNode node, BufferedWriter bw) {
		if (node == null)
			return;
		try {
			doInorderTraversal(node.left, bw);
			for (int i = 0; i < node.count; i++) {
				bw.write(node.payload);
				bw.newLine();
				if (node.red)
					System.out.println("red");
				else
					System.out.println("black");
			}
			doInorderTraversal(node.right, bw);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	// �׽�Ʈ�� ���� �Լ�
	public void inorderTraversal(BufferedWriter bw) {
		doInorderTraversal(root, bw);
	}
}*/

