static const char* clean_filename(const char* path)
{
    const char* filename = path + strlen(path);

    while (filename > path)
    {
        if (*filename == '/' || *filename == '\\')
        {
            return filename + 1;
        }

        filename--;
    }

    return path;
}
