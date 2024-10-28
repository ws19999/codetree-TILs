fun main()
{
    val n=readLine()!!.toInt()
    var cnt=0
    var sums=0
    var avg=0.0
    val nums=readLine()!!.trim().split(" ").map{it.toInt()}
    for(i in 0..n-1)
    {
        if(nums[i]%7==0)
        {
            cnt++
            sums+=nums[i]
        }
    }
    print("${cnt} ${sums} ${String.format("%.1f",sums/cnt)}")
}