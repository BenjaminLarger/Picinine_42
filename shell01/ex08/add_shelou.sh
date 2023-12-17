#!/bin/bash

BASE5='\"\?!'
BASE10='01234'

FT_NBR1='\"?!'

FT_NBR1_BASE10=$(echo "$FT_NBR1" | tr "$BASE5" "$BASE10")

echo "FT_NBR1 en base 10 : $FT_NBR1_BASE10"
