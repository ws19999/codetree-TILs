fun main(){
    val str=readLine()!!
    repeat(str.length+1){
        for(i in it..it+str.length-1)print("${str[i%str.length]}")
        println()
    }
}