csc /t:library /out:Blitz2k18Helper.dll Blitz2k18Helper.cs
csc /reference:Blitz2k18Helper.dll -out:MyBot.exe MyBot.cs
csc /reference:Blitz2k18Helper.dll -out:RandomBot.exe RandomBot.cs 
blitz2k18.exe -f 2 -d "30 30" "MyBot.exe" "RandomBot.exe"
