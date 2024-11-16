fun main()
{
    var arr=Array(3){IntArray(3){0}}
    for(i in 0..2)
    {
        arr[i]=readLine()!!.trim().split(" ").map{it.toInt()}.toIntArray()
    }
    for(i in 0..2)
    {
        var num=0
        for(j in 0..2)
        {
            num+=arr[i][j]
        }
        print("${String.format("%.1f",num.toDouble()/3)} ")
    }
    print("\n")
    for(i in 0..2)
    {
        var num=0
        for(j in 0..2)
        {
            num+=arr[j][i]
        }
        print("${String.format("%.1f",num.toDouble()/3)} ")
    }
    print("\n")
    var num=0
    for(i in 0..2)
    {
        for(j in 0..2)
        {
            num+=arr[i][j]
        }
    }
    print("${String.format("%.1f",num.toDouble()/9)} ")
}