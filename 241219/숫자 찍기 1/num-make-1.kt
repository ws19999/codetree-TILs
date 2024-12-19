fun main(){
    val (a,b)=readLine()!!.split(" ").map{it.toInt()}
    when(b){
        1 -> {
            val arr = Array(2*a){0}
            var num=0
            for(i in 0..a-1){
                if(i%2==0){
                    for(j in 0..i){
                        arr[j]=++num
                    }
                }
                else{
                    for(j in i downTo 0){
                        arr[j]=++num
                    }
                }
                for(j in 0..i)print("${arr[j]} ")
                println()
            }
            
        }
        2 -> {
            repeat(a){
                num -> 
                    repeat(num*2){
                        print(" ")
                    }
                    repeat((a-num)*2-1){
                    print("$num ")
                }
                println()
            }
        }
        3 -> {
            for(i in 1..a/2+1){
                for(j in 1..i)print("$j ")
                println()
            }
            for(i in a/2 downTo 1){
                for(j in 1..i)print("$j ")
                println()
            }
        }
    }
}