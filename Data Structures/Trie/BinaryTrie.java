import java.util.Arrays;

public class BinaryTrie {
    public static final int NUMBEROFNODES=1000000;
    public static final int LG=29;

    public class Node{
        int child[];
        int exist, cnt;

        public Node() {
            this.child = new int[2];
            this.exist = 0;
            this.cnt = 0;
        }
    }

    int cur;
    Node[] nodes;

    public BinaryTrie() {
        this.cur = 0;
        this.nodes = new Node[NUMBEROFNODES];
    }

    private int new_node() {
        cur++;
        Arrays.fill(nodes[cur].child, -1);
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    private void add_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    private void delete_number(int x) {
        if (find_number(x) == false) return;
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;

            int tmp = nodes[pos].child[c];
            nodes[tmp].cnt--;
            if (nodes[tmp].cnt == 0) {
                nodes[pos].child[c] = -1;
                return;
            }

            pos = tmp;
        }
        nodes[pos].exist--;
    }

    private boolean find_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = ((x & (1 << i))>0 ? 1 : 0);
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }
}
