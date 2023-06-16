import java.util.Arrays;

public class Trie {
    public static final int NUMBEROFNODES=1000000;
    private class Node{
        private int child[]=new int[26];
        private int exist;
        private int cnt;
    }

    private Node[] nodes;
    private int cur;//  Now how many nodes that trie has

    public Trie() {
        this.nodes =new Node[NUMBEROFNODES];
        this.cur = 0;
        Arrays.fill(nodes[0].child, -1);
        nodes[0].cnt=nodes[0].exist=0;
    }

    private int new_node(){
        ++cur;
        Arrays.fill(nodes[cur].child, -1);
        nodes[cur].cnt=nodes[cur].exist=0;
        return cur;
    }

    private void add_string(String s){
        int pos=0;
        for(int i=0; i<(int)s.length(); i++){
            int c=s.charAt(i)-'a';
            if(nodes[pos].child[c]==-1){
                nodes[pos].child[c]=new_node();
            }
            pos=nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    private boolean delete_string_recursive(int pos, String s, int i){
        if(i!=s.length()){
            int c=s.charAt(i)-'a';
            boolean isChildDeleted=delete_string_recursive(nodes[pos].child[c], s, i+1);
            if(isChildDeleted){
                nodes[pos].child[c]=-1;
            }
        }else{
            nodes[pos].exist--;
        }
        if(pos!=0){
            nodes[pos].cnt--;
            if(nodes[pos].cnt==0){
                return true;
            }
        }
        return false;
    }

    private boolean find_string(String s){
        int pos=0;
        for(int i=0; i<s.length(); i++){
            int c=s.charAt(i)-'a';
            if(nodes[pos].child[c]==-1){
                return false;
            }
            pos=nodes[pos].child[c];
        }
        return (nodes[pos].exist!=0);
    }

    private void delete_string(String s){
        if(find_string(s)==false)return;
        delete_string_recursive(0, s, 0);
    }

}
