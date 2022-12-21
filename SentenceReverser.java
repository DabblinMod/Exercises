import java.io.*;
import java.util.*;

class SentenceReverser {



  static char[] reverseWords(char[] arr) {
    // your code goes here
    String s=new String(arr);//creates a string 
    String[] splitWs=s.split(" ");//we create a string version of each space separated word
    //to reverse the sentence we create an ArrayList that will flip each string
    ArrayList<String> reversed=new ArrayList<String>();
    for(int i=splitWs.length-1; i > -1; i--){
      reversed.add(splitWs[i]);//creates an array list that reverses the sentence
    }
    s=""; //resets the string
    for(int i=0; i < reversed.size(); i++){
      s+=reversed.get(i);
      if(i >=0 && i < reversed.size()-1)
        s+=" ";
    }
    char[] flipped=s.toCharArray();
    for(int i=0; i < flipped.length; i++){
      arr[i]=flipped[i];
    }
    return arr;
    
  }

  public static void main(String[] args) {
    
  }

}