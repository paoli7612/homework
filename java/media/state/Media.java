package state;

import java.util.*;

public class Media {
  List<Integer> numbers;

  public Media(){
    this.numbers = new ArrayList<Integer>();
  }

  public void add(Integer n){
    this.numbers.add(n);
  }

  public Integer get(Integer i){
    return this.numbers.get(i);
  }

  public Integer getLen(){
    return this.numbers.size();
  }

  public Float calculate(){
    Integer sum = 0, len;
    len = this.getLen();

    for (int i=0; i<len; i++){
      sum += this.get(i);
    }
    Float media = (float)sum / len;
    return media;
  }
}
