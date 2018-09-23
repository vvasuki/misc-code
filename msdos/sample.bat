for /r . %G IN (*.java) do perl -pi.bak -e "s/com.microsoft.ts.client.UI/com.microsoft.ts.client.ui/g" "%G"
for /r . %G IN (*.java.bak) do del /f "%G"
for /r . %G IN (*.java) do perl -pi.bak -e "s/([a-zA-Z0-9_]+)\.getBytes\(\)/Object2BytesUtility.object2bytes(\1)/g" "%G"
for /r . %G IN (*.java.bak) do del "%G"
