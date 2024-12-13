fun main(){
    val (a,b)=readLine()!!.split(" ").map{it.toInt()}
    when(b){
        1 -> {
            repeat(a){
                for(i in 0..it)print("*")
                println()
            }
        }
        2 -> {
            repeat(a){
                for(i in 1..a-it)print("*")
                println()
            }
        }
        3 -> {
            repeat(a){
                for(i in 2..a-it)print(" ")
                for(i in 1..it*2+1)print("*")
                println()
            }
        }
    }
}