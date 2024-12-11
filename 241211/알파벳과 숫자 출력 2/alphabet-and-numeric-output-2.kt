fun main(){
    val N=readLine()!!.toInt()
    var c='A'
    var num=0
    for(i in N downTo 0){
        repeat(i){
            print("$c ")
            c++
            if(c>'Z')c='A'
        }
        repeat(N-i){
            print("$num ")
            num++
            if(num>9)num=0
        }
        println()
    }
}