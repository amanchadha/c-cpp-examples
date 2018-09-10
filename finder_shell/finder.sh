search()
{
   for d in *
   do
   if [ -d "$d" ]
   then
   (cd "$d" && search)
   fi

   find . -name "PASS"
   done
}

search
