#!/usr/bin/env python3
blocklist = ["/","setattr","compile","os","import","_","breakpoint","exit","lambda","eval","exec","read","print","open","'","=","builtins","clear"]


def main():
	global blocklist

	print("=" * 60)
	print("Welcome to jail! We'll let you out if you find the flag :)\n")
	print("But be careful! Some commands are in a \"blocklist\"")
	print("=" * 60)

	while True:
		cmd = input('Enter command: ')

		for blocked in blocklist:
			if blocked in cmd:
				print("Blocklisted content detected! Exiting!")
				exit(0)

		try:
			exec(cmd)
		except NameError as e:
			print(e)


if __name__ == "__main__":
	main()
