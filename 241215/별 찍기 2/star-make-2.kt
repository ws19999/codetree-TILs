fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val (f,s)=readLine()!!.split(" ").map{it.toInt()}
    when(s){
        1 -> {
            for(i in 1..f/2){
                repeat(i) {
                    print("*")
                }
                println()
            }
            for(i in f/2+1 downTo 1){
                repeat(i){
                    print("*")
                }
                println()
            }
        }
        2 -> {
            for(i in f/2 downTo 0){
                repeat(i){
                    print(" ")
                }
                repeat(f/2+1-i){
                    print("*")
                }
                println()
            }
            for(i in 1..f/2){
                repeat(i){
                    print(" ")
                }
                repeat(f/2+1-i){
                    print("*")
                }
                println()
            }
        }
        3 -> {
            for(i in f/2 downTo 0){
                repeat(f/2-i){
                    print(" ")
                }
                repeat(2*i+1){
                    print("*")
                }
                println()
            }
            for(i in 1..f/2){
                repeat(f/2-i){
                    print(" ")
                }
                repeat(2*i+1){
                    print("*")
                }
                println()
            }
        }
        4 -> {
            for(i in 0..f/2){
                repeat(i){
                    print(" ")
                }
                repeat(f/2+1-i){
                    print("*")
                }
                println()
            }
            for(i in 2..f/2+1){
                repeat(f/2){
                    print(" ")
                }
                repeat(i){
                    print("*")
                }
                println()
            }
        }
    }
}