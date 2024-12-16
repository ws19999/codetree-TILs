fun main(){
    val N=readLine()!!.toInt()
    repeat(N/2+1){
        for(i in 1..it)print(" ")
        for(i in 1..it*2+1)print("*")
        println()
    }
    for(i in N/2-1 downTo 0){
        for(j in 1..i)print(" ")
        for(j in 1..i*2+1)print("*")
        println()
    }
}