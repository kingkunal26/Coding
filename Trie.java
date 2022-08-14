class Node{
    Node links[]=new Node[26];
    int cntEndsWith=0;
    int cntPrefix=0;
    public Node(){
    }
    public boolean containsKey(char ch)
    {
        return (links[ch-'a']!=null);
    }
    public void put(char ch,Node node)
    {
        links[ch-'a']=node;
    }
    public Node get(char ch)
    {
        return links[ch-'a'];
    }
    public void increasePrefix(){
        cntPrefix++;
    }
    public void increaseEnd(){
        cntEndsWith++;
    }
    public int getEnd(){
        return cntEndsWith;
    }
    public int getPrefix()
    {
        return cntPrefix;
    }
    public void deleteEnd() {
        cntEndsWith--; 
    }
    public void reducePrefix() {
        cntPrefix--; 
    }
}
public class Trie {
    private Node root;
    public Trie() {
        root=new Node();
    }

    public void insert(String word) {
        Node node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node.containsKey(word.charAt(i)))
            {
                node.put(word.charAt(i),new Node());
            }
            node=node.get(word.charAt(i));
            node.increasePrefix();
        }
        node.increaseEnd();
    }

    public int countWordsEqualTo(String word) {
        Node node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node.containsKey(word.charAt(i)))
            {
                return 0;
            }
            node=node.get(word.charAt(i));
        }
        return node.getEnd();
    }

    public int countWordsStartingWith(String word) {
        Node node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node.containsKey(word.charAt(i)))
            {
                node=node.get(word.charAt(i));
            }
            else
            {
                return 0;
            }
        }
        return node.getPrefix();
    }

    public void erase(String word) {
        Node node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node.containsKey(word.charAt(i)))
            {
                node=node.get(word.charAt(i));
                node.reducePrefix();
            }
            else
            {
                return;
            }
        }
        node.deleteEnd();
    }

}