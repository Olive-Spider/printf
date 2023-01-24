for (i = 0; format && format[i] != '\0'; i++)
{
	if (format[i] != '%')
	{
		buffer[buff_ind++] = format[i];
		if (buff_ind == BUFF_SIZE)
			print_buffer(buffer, &buff_ind);
/* write(1, &format[i], 1);*/
		printed_chars++;
	}
	else
	{
		print_buffer(buffer, &buff_ind);
		flags = get_flags(format, &i);
		width = get_width(format, &i, list);
		precision = get_precision(format, &i, list);
		size = get_size(format, &i);
		++i;
		printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
		if (printed == -1)
			return (-1);
		printed_chars += printed;
	}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
