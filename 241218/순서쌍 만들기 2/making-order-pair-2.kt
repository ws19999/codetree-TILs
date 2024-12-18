fun main(){
    val n=readLine()!!.toInt()
    for(i in 1..n){
        for(j in 1..n){
            print("(${i*i},${j*j}) ")
        }
        println()
    }
}