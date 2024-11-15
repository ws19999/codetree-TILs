fun main()
{
    val N=readLine()!!.toInt()
    var arr=Array(N){IntArray(N){0}}
    for(i in 0..N-1)
    {
        var tmp=readLine()!!.split(" ").map{it.toInt()}.toIntArray()
        arr[i]=tmp
    }
    for(i in 0..N-1)
    {
        if(i%2==0)
        {
            for(j in 0..N-1)arr[i][j]=1

        }
    }
    for(i in 0..N-1)
    {
        for(j in 0..N-1)
        {
            if(j%2==1)arr[i][j]=2
            print("${arr[i][j]} ")
        }
        print("\n")
    }
    
}