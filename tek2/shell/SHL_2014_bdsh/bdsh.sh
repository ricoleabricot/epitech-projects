#!/bin/sh

noArgCheck() { 
	if [ -z "$1" ]; then
		echo "Syntax error :
		USAGE - bdsh.sh [-k] [-f <db_file>] (put (<clef> | $<clef>) (<valeur> | $<clef>) | del (<clef> | $<clef>) [<valeur> | $<clef>] | select [<expr> | $<clef>] | flush)" >&2
		exit 1
	fi
}

argLoop() {
	for var in "$@"
	do
		if [ "$TMP" = "database" ]; then
			TMP="NULL"
			DATABASE="$var"
			continue
		elif [ "$TMP" = "key" ]; then
			if [ $ACTION = "select" ]; then
				TMP="NULL"
			else
				TMP="value"
			fi
			KEY="$var"
			continue
		elif [ "$TMP" = "value" ]; then
			TMP="NULL"
			VALUE="$var"
			continue
		fi

		if [ "$var" = "-k" ]; then
			OPTION="true"

		elif [ "$var" = "-f" ]; then
			TMP="database"

		elif [ "$var" = "put" ]; then
			ACTION="put"
			TMP="key"

		elif [ "$var" = "del" ]; then
			ACTION="del"
			TMP="key"

		elif [ "$var" = "select" ]; then
			ACTION="select"
			TMP="key"

		elif [ "$var" = "flush" ]; then
			ACTION="flush"

		else
			echo "Syntax error : Unknown command $var" >&2
			exit 1
		fi
	done
}

createDatabase() {
	if [ -z "$DATABASE" ]; then
		DATABASE="sh.db"
	fi
}

findValue() {
	echo "$KEY" | grep -q -e"^$.*" 
	if [ $? = 0 ]; then
		KEY=$( echo "$KEY" | cut -d"$" -f2- )
		grep -q -e"^$KEY=.*" "$DATABASE"
		if [ $? = 0 ]; then
			KEY=$( grep	-e"^$KEY=" "$DATABASE" | cut -d'=' -f2- )
		else
			echo "No such key : $KEY"
			exit 1
		fi
	fi

	echo "$VALUE" | grep -q -e"^$.*" 
	if [ $? = 0 ]; then
		VALUE=$( echo "$VALUE" | cut -d"$" -f2- )
		grep -q -e"^$VALUE=.*" "$DATABASE"
		if [ $? = 0 ]; then
			VALUE=$( grep -e"^$VALUE=" "$DATABASE" | cut -d'=' -f2- )
		else
			echo "No such key : $VALUE"
			exit 1
		fi
	fi
}

valueCheck() {
	if [ "$ACTION" = "none" ]; then
		echo "Syntax error : No action selected" >&2
		exit 1
	elif [ "$ACTION" != "put" ] && [ ! -e "$DATABASE" ]; then
		echo "No base found : file $DATABASE" >&2
		exit 1
	elif [ "$ACTION" = "put" ]; then
		if [ "$KEY" = "NULL" ] || [ "$VALUE" = "NULL" ]; then
			echo "Syntax error : USAGE - put (<clef> | $<clef>) (<valeur> | $<clef>)" >&2
			exit 1
		fi
	elif [ "$ACTION" = "del" ]; then
		if [ "$KEY" = "NULL" ]; then
			echo "Syntax error : USAGE - del (<clef> | $<clef>) [<valeur> | $<clef>] | select [<expr> | $<clef>]" >&2
			exit 1
		fi
	fi
}

put() {
	if [ ! -e "$DATABASE" ]; then
		flush
	fi

	grep -q -e"^$KEY=.*" "$DATABASE"
	if [ $? = 0 ]; then
		sed -i "$DATABASE" -e "s/^$KEY=.*/$KEY=$VALUE/g"
	else
		echo "$KEY=$VALUE" >> "$DATABASE"
	fi
}

del() {
	if [ "$VALUE" = "NULL" ]; then
		sed -i "$DATABASE" -e "s/^$KEY=.*/$KEY=/g"
	else
		sed -i "$DATABASE" -e "/^$KEY=$VALUE/d"
	fi
}

sel() {
	if [ "$KEY" = "NULL" ]; then
		if [ "$OPTION" = "false" ]; then
			cut -d'=' -f2- "$DATABASE"
		else
			cat "$DATABASE"
		fi
	else
		if [ "$OPTION" = "false" ]; then
			grep -e"^[^=]*$KEY.*=" "$DATABASE" | cut -d'=' -f2-
		else
			cat "$DATABASE" | grep -e"^[^=]*$KEY.*="
		fi
	fi

	exit 0
}

flush() {
	echo -n "" > "$DATABASE"
}

actionLoop() {
	case "$ACTION" in
		"put")
			put
		;;
		"del")
			del
		;;
		"select")
			sel
		;;
		"flush")
			flush
		;;
	esac
}

OPTION="false"
DATABASE=""
ACTION="none"
KEY="NULL"
VALUE="NULL"
TMP="NULL"

noArgCheck $1
argLoop "$@"
createDatabase
findValue
valueCheck
actionLoop
