void probing_process(int &int_sum, float &float_sum) {
  MPI_Status status;
  
  // 1- Probe the incoming message
  MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

  // 2- Get the tag and the source
  int tag = status.MPI_TAG;
  int source = status.MPI_SOURCE;

  // Printing the message
  std::cout << "Received a message from process " << source << " with tag " << tag << std::endl;

  // 3- Add to int_sum or float_sum depending on the tag of the message
  if (tag)
  {
    float f;
    MPI_Recv(&f, 1, MPI_FLOAT, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    float_sum += f;
  }
  else
  {
    int i;
    MPI_Recv(&i, 1, MPI_INT, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    int_sum += i;
  }
}
